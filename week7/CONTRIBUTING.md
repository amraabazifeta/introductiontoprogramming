# Contributing Guide

This document explains how to write a good pull request in this repository.  
Read it before opening your first PR.

---

## What Makes a Good Pull Request?

A good PR does three things:
1. **Shows working code** with test output as evidence.
2. **Explains the thinking** behind every decision (the Teach-Back section).
3. **Makes it easy for a reviewer** to understand what changed and why.

A PR that is just "here is my code" will be returned for revision.

---

## The Teach-Back Section (Required)

Every PR must include a Teach-Back section. This is not optional.  
Write it **in your own words** — do not copy from course notes or the internet.

Answer these four questions:
1. What does this code do, step by step?
2. What is the most important concept in this solution?
3. What would break if you removed [pick one specific line]?
4. What confused you, and how did you resolve it?

A one-line answer to each question is not enough. Write 2–4 sentences per question.

---

## Code Review Etiquette

**As a Reviewer:**
- Read every line before commenting.
- Ask "why?" for anything unclear — do not assume.
- Be specific: "Line 12: why use a list here instead of a dictionary?" is good. "Looks fine" is not.
- Approve only when you genuinely understand and agree with the solution.
- Do not approve a PR with an empty Teach-Back section.

**As a Coder receiving a review:**
- Respond to every comment — either fix it or explain why you disagree.
- Do not merge until all comments are resolved.
- Say thank you. Code review is a gift.

---

## PR Size

- One PR = one concept or one project section.
- If your PR touches more than 3 files, split it.
- Small PRs get reviewed faster and teach more.

---

## Before You Open a PR — Checklist

- [ ] Branch name follows the convention (`yourname/week1`, `yourname/project2`, etc.)
- [ ] Commit messages follow the convention (`feat(week1): ...`)
- [ ] Code runs without errors
- [ ] Expected output matches what the problem description requires
- [ ] Teach-Back section is fully written
- [ ] You have requested at least one peer reviewer
