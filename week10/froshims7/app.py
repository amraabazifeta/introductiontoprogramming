# Implements a registration form, storing registrants in a SQLite database, with support for multiple sports and deregistration

# TODO: Import SQL from cs50
from cs50 import SQL

# TODO: Import Flask, redirect, render_template, and request from flask
from flask import Flask, redirect, render_template, request

# TODO: Create the Flask app instance
app = Flask(__name__)

# TODO: Connect to "froshims.db" with cs50's SQL() and store in db
db = SQL("sqlite:///froshims.db")

# TODO: Define the SPORTS list with at least 3 sport names
SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

# TODO: Define a GET route for "/" that renders index.html with sports=SPORTS
@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

# TODO: Define a POST route for "/deregister" that:
#         - Reads "id" from the form
#         - If id exists, deletes the row: DELETE FROM registrants WHERE id = ?
#         - Redirects to "/registrants"
@app.route("/deregister", methods=["POST"])
def deregister():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

# TODO: Define a POST route for "/register" that:
#         1. Validates name (missing → error.html message="Missing name")
#         2. Uses request.form.getlist("sport") to get all selected sports
#         3. If the list is empty → error.html message="Missing sport"
#         4. If any sport is not in SPORTS → error.html message="Invalid sport"
#         5. Inserts one row per sport into the database
#         6. Redirects to "/registrants"
@app.route("/register", methods=["POST"])
def register():
    # 1. Validate name
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")

    # 2. Get multiple sports using getlist
    sports = request.form.getlist("sport")

    # 3. Check if list is empty
    if not sports:
        return render_template("error.html", message="Missing sport")

    # 4. & 5. Validate each sport and insert rows
    for sport in sports:
        if sport not in SPORTS:
            return render_template("error.html", message="Invalid sport")
        db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # 6. Redirect
    return redirect("/registrants")

# TODO: Define a GET route for "/registrants" that:
#         - Queries all registrants from the database
#         - Renders registrants.html passing the results as "registrants"
@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)