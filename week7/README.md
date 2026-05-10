# CS50 Python & CSV — Collaborative Learning Repository

Welcome! This is the class repository for **Introduction to Programming** (CS50-style).  
You will learn Python CSV processing, build real projects, review your peers' code, and explain your thinking in pull requests. **All three activities are assessed.**

---

## 📁 Repository Structure

```
cs50-python-csv/
├── week1/          ← CSV basics: csv.reader, DictReader, counting
├── week2/          ← Sorting, SQL, parameterised queries
├── mini-projects/  ← 4 graded in-class projects
└── challenges/     ← Optional extension problems
```

---

## 🚀 Quick Start (Do This First)

```bash
# 1. Accept the GitHub Classroom assignment link (from your instructor)
# 2. Clone YOUR fork
git clone https://github.com/YOUR-USERNAME/cs50-python-csv.git
cd cs50-python-csv

# 3. Add the upstream remote so you can pull updates
git remote add upstream https://github.com/COURSE-ORG/cs50-python-csv.git

# 4. Create your first branch (replace 'yourname')
git checkout -b yourname/week1

# 5. Work, commit, push, open a PR
git add .
git commit -m "feat(week1): add DictReader solution"
git push origin yourname/week1
# Then open a Pull Request on GitHub: yourname/week1 → group/YOUR-TEAM
```

---

## 🌿 Branching Strategy

| Branch | Purpose | Who commits |
|--------|---------|-------------|
| `main` | Protected. Clean, reviewed solutions only | Instructor only |
| `group/<team-name>` | Shared team branch. Base for all your work | Instructor creates; team merges into |
| `<yourname>/week<n>` | Your weekly exercises (e.g. `amira/week1`) | You |
| `<yourname>/project<n>` | Your mini-project work (e.g. `jorge/project2`) | You |
| `hotfix/<issue-number>` | Fix a bug found after merge | Team member who spotted it |

### Rules (non-negotiable)
1. **Never commit directly to `main` or your group branch.**
2. Always branch from your **group branch**, not from `main`.
3. Branch names must follow the naming convention — PRs with wrong names are returned unreviewed.
4. Delete your feature branch after the PR is merged.

---

## 💬 Commit Message Format

```
type(scope): short description

Types : feat | fix | docs | test | refactor | style
Scopes: week1 | week2 | project1 | project2 | project3 | project4

Examples:
  feat(week1): switch reader to DictReader
  fix(project2): handle KeyError for empty CSV rows
  docs(week2): add comments explaining sorted() key argument
  test(project3): add edge case for zero-attendee event
```

---

## 👥 The Four Roles

Roles rotate every project so everyone practises everything.

| Role | Responsibility | GitHub Duty |
|------|---------------|-------------|
| 🧑‍💻 **Coder** | Writes the working solution | Opens PR; fills code sections |
| 🔍 **Reviewer** | Ensures code quality | Leaves inline comments; must approve before merge |
| 🧪 **Tester** | Verifies correctness with real inputs | Pastes test output as PR evidence |
| 🏫 **Mentor** | Supports the group; asks questions, never gives answers | Writes the Teach-Back section in the PR |

---

## 🔄 Workflow Step by Step

```
1. Read the problem brief in the project README
2. Think individually for 8–10 minutes (no code yet — write in plain English)
3. Discuss as a group — agree on data structures and approach
4. Coder types; Reviewer watches and asks "why?"; Tester runs code
5. Open a PR using the PR template — fill in EVERY section
6. Reviewer leaves at least 2 inline comments
7. Tester adds test output as a PR comment
8. Mentor completes the Teach-Back section
9. Merge only after: teach-back done ✓ + peer approved ✓ + test evidence shown ✓
```

---

## ❓ Getting Help

- **Stuck on a concept?** Open an Issue using the `question` template. Tag `@programming-coach`.
- **Found a bug after merging?** Open an Issue with the `bug` template, then create a `hotfix/` branch.
- **Want to discuss an approach?** Comment directly on the relevant PR or commit.

> 💡 Do not ask for help in WhatsApp or private messages. All discussion belongs in GitHub Issues and PR comments so the whole class can learn from it.

---

## 📊 Assessment Weights

| Component | Weight |
|-----------|--------|
| Working code (correct output) | 40% |
| Teach-Back PR description | 30% |
| Code review comments given to peers | 15% |
| Commit history, branching, PR workflow | 15% |

---

*Questions about the repository setup? Open an Issue with the `question` template.*
