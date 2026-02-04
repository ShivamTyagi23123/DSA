import subprocess
import random
from datetime import datetime, timedelta
import os

REPO_PATH = r"c:\Users\Admin\Desktop\python or AIML\DSA-fix"
os.chdir(REPO_PATH)
TIMEZONE = "+05:30"

# Date range: last 3 months
end_date = datetime(2026, 5, 3)
start_date = datetime(2026, 2, 4)

# ============================================================
# Get all commits in chronological order (oldest first)
# ============================================================
result = subprocess.run(
    ["git", "log", "--format=%H|%s", "--reverse"],
    capture_output=True, text=True, check=True
)

commits = []
for line in result.stdout.strip().split("\n"):
    parts = line.split("|", 1)
    if len(parts) == 2:
        commits.append({"hash": parts[0].strip(), "message": parts[1].strip()})

num_commits = len(commits)
print(f"Found {num_commits} commits to rewrite.\n")

# ============================================================
# Generate sorted random dates over last 3 months, 10PM-2AM
# ============================================================
def random_late_night():
    delta = (end_date - start_date).days
    random_day = start_date + timedelta(days=random.randint(0, delta))
    total_minutes = random.randint(22 * 60, 25 * 60 + 59)
    hour = total_minutes // 60
    minute = total_minutes % 60
    second = random.randint(0, 59)
    if hour >= 24:
        random_day += timedelta(days=1)
        hour -= 24
    return random_day.replace(hour=hour, minute=minute, second=second)

dates = sorted([random_late_night() for _ in range(num_commits)])

# ============================================================
# Get tree hashes for each commit
# ============================================================
print("Reading commit trees...")
commit_data = []
for i, c in enumerate(commits):
    tree = subprocess.run(
        ["git", "rev-parse", f"{c['hash']}^{{tree}}"],
        capture_output=True, text=True, check=True
    ).stdout.strip()
    new_date = dates[i].strftime(f"%Y-%m-%dT%H:%M:%S{TIMEZONE}")
    commit_data.append({
        "tree": tree,
        "message": c["message"],
        "new_date": new_date
    })
    print(f"  {c['hash'][:8]} -> {new_date} | {c['message']}")

# ============================================================
# Rebuild history on orphan branch
# ============================================================
print(f"\n{'='*60}")
print("Rebuilding history with random dates + late-night times...")
print(f"{'='*60}\n")

subprocess.run(["git", "checkout", "--orphan", "rewritten"], check=True)
subprocess.run(["git", "reset", "--hard"], check=True)

for i, cd in enumerate(commit_data):
    subprocess.run(["git", "read-tree", cd["tree"]], check=True)
    subprocess.run(["git", "checkout-index", "-a", "-f"], check=True)
    subprocess.run(["git", "add", "-A"], check=True)

    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = cd["new_date"]
    env["GIT_COMMITTER_DATE"] = cd["new_date"]

    subprocess.run(
        ["git", "commit", "-m", cd["message"], "--allow-empty"],
        env=env, check=True,
        capture_output=True  # suppress verbose output
    )
    print(f"  [{i+1}/{len(commit_data)}] {cd['new_date']}  — {cd['message']}")

# ============================================================
# Replace main branch
# ============================================================
subprocess.run(["git", "branch", "-D", "main"], check=True)
subprocess.run(["git", "branch", "-m", "main"], check=True)

print(f"\n{'='*60}")
print(f"SUCCESS! {len(commit_data)} commits rewritten.")
print(f"All dates randomized across Feb 4 - May 3, 2026")
print(f"All times between 10 PM - 2 AM IST")
print(f"{'='*60}")
print("\nNow run: git push -f origin main")
