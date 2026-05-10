#!/bin/bash
# setup.sh — Initialize all practice databases for Week 8 SQL exercises
# Usage: bash setup.sh

set -e

echo "🗄️  Week 8 SQL — Database Setup"
echo "================================"

# Check for sqlite3
if ! command -v sqlite3 &>/dev/null; then
    echo "❌ sqlite3 not found."
    echo "   Install it:"
    echo "   • Ubuntu/Debian: sudo apt install sqlite3"
    echo "   • macOS:         brew install sqlite"
    echo "   • Windows:       https://www.sqlite.org/download.html"
    exit 1
fi

echo "✅ sqlite3 found: $(sqlite3 --version)"

# Remove old databases if they exist
rm -f data/school.db data/library.db

# Build databases
echo ""
echo "📦 Creating school.db..."
sqlite3 data/school.db < data/school.sql
echo "   ✅ school.db created"
echo "      Tables: $(sqlite3 data/school.db '.tables')"

echo ""
echo "📦 Creating library.db..."
sqlite3 data/library.db < data/library.sql
echo "   ✅ library.db created"
echo "      Tables: $(sqlite3 data/library.db '.tables')"

echo ""
echo "🎉 Setup complete! You're ready to start."
echo ""
echo "Quick start:"
echo "  sqlite3 data/school.db"
echo "  > .headers on"
echo "  > .mode column"
echo "  > SELECT * FROM students LIMIT 5;"
echo ""
echo "Exercises:"
echo "  01-basics      → exercises/01-basics/"
echo "  02-queries     → exercises/02-queries/"
echo "  03-joins       → exercises/03-joins/"
echo "  04-aggregates  → exercises/04-aggregates/"
echo "  05-subqueries  → exercises/05-subqueries/"
echo "  06-design      → exercises/06-design/"
echo "  07-advanced    → exercises/07-advanced/"
echo ""
echo "Good luck! 🚀"
