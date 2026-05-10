# Instructor Setup Guide — GitHub Classroom

This file is for **instructors only**. Students do not need to read this.  
Delete or move this file before publishing the student-facing template.

---

## Step 1 — Create the Template Repository

1. Go to [github.com](https://github.com) and create a new **public** repository named `cs50-python-csv`.
2. Push the contents of this folder to that repository:
   ```bash
   cd cs50-python-csv
   git init
   git add .
   git commit -m "chore: initial course repository"
   git branch -M main
   git remote add origin https://github.com/YOUR-ORG/cs50-python-csv.git
   git push -u origin main
   ```
3. Go to **Settings → Template repository** and tick the checkbox.  
   This makes it available as a GitHub Classroom template.

---

## Step 2 — Protect the Main Branch

In your repository: **Settings → Branches → Add rule**

- Branch name pattern: `main`
- ✅ Require a pull request before merging
- ✅ Require at least 1 approval
- ✅ Dismiss stale PR approvals when new commits are pushed
- ✅ Do not allow bypassing the above settings

---

## Step 3 — Create Group Branches

Before students start, create one branch per learning group:

```bash
git checkout -b group/team-alpha && git push origin group/team-alpha
git checkout main
git checkout -b group/team-beta  && git push origin group/team-beta
git checkout main
# repeat for each group
```

Protect group branches the same way as `main` (require 1 PR approval).

---

## Step 4 — Set Up GitHub Classroom

1. Go to [classroom.github.com](https://classroom.github.com)
2. Create a new **Group Assignment**
3. Select your template repository (`cs50-python-csv`)
4. Set:
   - **Starter code:** your template repo
   - **Visibility:** Private (each team gets their own private fork)
   - **Maximum team size:** 4
   - **Deadline:** set per your schedule
5. Share the assignment link with students

---

## Step 5 — Configure the Solutions Folder

The `.gitignore` excludes `week1/solutions/` and `week2/solutions/` from student forks automatically.

To reveal solutions after a deadline:
1. Remove the relevant lines from `.gitignore` on the `main` branch
2. Push — students can then pull and see the solutions

Alternatively, publish solutions as a separate release on GitHub:
**Releases → Draft a new release → attach solution files as assets**

---

## Step 6 — Add Labels to the Repository

Create these labels under **Issues → Labels → New label**:

| Label | Colour | Purpose |
|-------|--------|---------|
| `question` | `#0075ca` | Student needs concept clarification |
| `bug` | `#d73a4a` | Something in the code is broken |
| `help-wanted` | `#e4e669` | Student is stuck; mentor should intervene |
| `discuss` | `#7057ff` | Instructor-seeded discussion prompt |
| `good-first-issue` | `#008672` | Beginner-friendly extension task |
| `needs-review` | `#ffa500` | PR awaiting peer review for 24+ hours |

---

## Step 7 — Seed Discussion Issues

At the start of each week, open 1–2 Issues with the `discuss` label to spark conversation.

**Week 1 discussion prompts:**
- "When would you choose `csv.reader` over `csv.DictReader`? Give a real-world example."
- "What happens to your counting code if the CSV has 1,000 languages instead of 3?"

**Week 2 discussion prompts:**
- "What can SQL do in one line that takes 10+ lines in Python? Share an example."
- "Why is `key=counts.get` written without parentheses? What would happen if you added them?"

---

## Week-by-Week Instructor Checklist

### Before Week 1
- [ ] Template repository created and marked as template
- [ ] `main` branch protected
- [ ] Group branches created (`group/team-alpha`, etc.)
- [ ] GitHub Classroom assignment created and link shared
- [ ] Labels added to repository
- [ ] Week 1 discussion Issues opened

### Before Week 2
- [ ] Review week 1 PRs — leave at least one comment per group
- [ ] Open Week 2 discussion Issues
- [ ] Confirm all students have merged their week1 branch

### Before each Mini Project session
- [ ] Announce role rotation (who is Coder/Reviewer/Tester/Mentor this week)
- [ ] Confirm Programming Coaches know which groups they support
- [ ] Check that the project's sample CSV is accessible in the repo

### After each Mini Project
- [ ] Read every PR Teach-Back section — add one comment per group
- [ ] Post a class-wide summary Issue: "Top 2 concepts the class found hard this week"
- [ ] Update the role rotation table in root README if needed

---

## Programming Coach Onboarding

Share this with TAs / senior students acting as Programming Coaches:

**Your job:**
- Support 2–3 groups per session without writing their code
- Ask Socratic questions: "What does that variable hold right now?"
- Respond to `help-wanted` Issues within 10 minutes during class
- Read each group's PR Teach-Back and leave one written comment before class ends

**Never do:**
- Type code for a student (not even "just this one line")
- Give a direct answer before asking at least one leading question
- Approve a PR without reading the Teach-Back section
- Interrupt a group that is making progress

**Your best phrase:** *"Interesting. What happens if you run it right now?"*
