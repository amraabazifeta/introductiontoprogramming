# Project 3 — Event Log Reporter

🟡 **Intermediate** · 35–45 minutes · Group of 3

---

## Problem Description

A community centre logs every room booking in a CSV file.  
Each row records a date, room name, event type, and number of attendees.

Write a program that reads the log and generates a **four-section report**:

1. **Bookings by room** — how many events each room hosted
2. **Bookings by event type** — how many events of each type occurred
3. **Busiest day** — the date with the highest total attendees
4. **Large events** — all events with more than 50 attendees, sorted by attendees descending

---

## Input

`bookings.csv` (already in this folder):
```
date,room,event_type,attendees
2025-03-01,Room A,Lecture,80
2025-03-01,Room B,Workshop,20
2025-03-02,Room A,Meeting,12
2025-03-02,Room C,Social,65
2025-03-03,Room A,Lecture,90
2025-03-03,Room B,Social,55
2025-03-04,Room C,Workshop,30
2025-03-04,Room A,Meeting,8
2025-03-05,Room B,Lecture,72
2025-03-05,Room C,Social,48
```

---

## Expected Output

```
=== Community Centre Booking Report ===

Bookings by Room:
  Room A : 4 events
  Room B : 3 events
  Room C : 3 events

Bookings by Event Type:
  Lecture  : 3 events
  Meeting  : 2 events
  Social   : 3 events
  Workshop : 2 events

Busiest Day: 2025-03-03  (145 total attendees)

Large Events (> 50 attendees):
  2025-03-03 | Room A  | Lecture  |  90 attendees
  2025-03-01 | Room A  | Lecture  |  80 attendees
  2025-03-05 | Room B  | Lecture  |  72 attendees
  2025-03-02 | Room C  | Social   |  65 attendees
  2025-03-03 | Room B  | Social   |  55 attendees
```

---

## Concepts Practised

- Reading multiple columns from a CSV simultaneously
- Building and updating **multiple dictionaries in a single pass**
- Finding a maximum with `max()` and `key=` argument
- Filtering a list with a condition
- Sorting a list of dictionaries by a field
- Multi-section formatted output

---

## Starter Scaffold

See `starter.py` in this folder.

---

## Group Roles for This Project

| Role | Responsibility |
|------|---------------|
| 🧑‍💻 Coder | Writes the CSV reading loop; builds all four data structures |
| 🧪 Tester | Adds more rows to `bookings.csv`; runs the code at each step; finds edge cases |
| 🏫 Mentor/Reviewer | Checks output formatting; writes the PR Teach-Back; asks "what if?" questions |

---

## Extension Ideas

1. Sort each section alphabetically (rooms A→Z, types A→Z) for consistent output
2. Add a fifth section: **Average attendees per event type**
3. Detect double-bookings: the same room on the same date appearing more than once
4. Accept a `--min` command-line argument to change the large-events threshold:  
   `python solution.py --min 40`
5. Write the large events section to a separate `large_events.csv` file

---

## Discuss Before Coding

> "We need four different counts/lists from one loop. Should we use four separate loops or one combined loop?"  
> Discuss as a group. What are the trade-offs? Which approach does the starter suggest?
