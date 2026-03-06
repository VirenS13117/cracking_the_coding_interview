import os
import json
from pathlib import Path
from slugify import slugify
from git import Repo
from anthropic import Anthropic

# OpenClaw Workspace Paths
# The script now lives in ~/.openclaw/agents/coder/workspace/scripts/
WORKSPACE_PATH = Path(__file__).resolve().parents[1]
LEETCODE_DIR = WORKSPACE_PATH / "leetcode"
LEETCODE_DIR.mkdir(exist_ok=True)

# Anthropic Client using the key from openclaw.json
client = Anthropic(api_key=os.environ.get("ANTHROPIC_API_KEY"))

PROMPT = """
You are a technical interview preparation assistant.
Pick ONE problem from the LeetCode Top Interview 150.
Rules: Prefer new problems, rotate topics.
Output format JSON:
{
  "problem_name": "",
  "topic": "",
  "leetcode_url": "",
  "markdown": "",
  "filename": ""
}
"""

def get_existing_files():
    return [f.stem for f in LEETCODE_DIR.glob("*.md")]

def generate_note(existing):
    avoid = ", ".join(existing)
    # Using Claude 4.6 Sonnet as configured in your JSON
    response = client.messages.create(
        model="claude-sonnet-4-6",
        max_tokens=4096,
        system=PROMPT,
        messages=[{"role": "user", "content": f"Avoid these: {avoid}"}]
    )
    import re
    text = response.content[0].text
    # Extract JSON from markdown code block if present
    match = re.search(r'```(?:json)?\s*(\{.*?\})\s*```', text, re.DOTALL)
    if match:
        text = match.group(1)
    else:
        # Try to find raw JSON object
        match = re.search(r'\{.*\}', text, re.DOTALL)
        if match:
            text = match.group(0)
    return json.loads(text)

def save_markdown(filename, markdown):
    path = LEETCODE_DIR / filename
    with open(path, "w") as f:
        f.write(markdown)
    return path

def commit_and_push(file_path, problem_name):
    try:
        repo = Repo(WORKSPACE_PATH)  # .git is at workspace root
        repo.git.add(file_path)
        repo.index.commit(f"Add LeetCode daily note: {problem_name}")
        origin = repo.remote(name="https://github.com/VirenS13117/cracking_the_coding_interview")
        origin.push()
        return True
    except Exception as e:
        print(f"Git Error: {e}")
        return False

def main():
    existing = get_existing_files()
    data = generate_note(existing)
    
    filename = data.get("filename") or (slugify(data["problem_name"]) + ".md")
    path = save_markdown(filename, data["markdown"])
    
    success = commit_and_push(path, data["problem_name"])
    
    # We print the result so the OpenClaw Agent can read it 
    # and send it to you on Telegram automatically
    status = "✅ Pushed to GitHub" if success else "❌ Git Push Failed"
    print(f"DSA Update: {data['problem_name']} ({data['topic']})\n{status}\n\n{data['markdown']}")

if __name__ == "__main__":
    main()
