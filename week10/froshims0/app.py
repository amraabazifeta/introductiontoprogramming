# Implements a registration form using a select menu without validating sport server-side

# TODO: Import Flask, render_template, and request from the flask package
from flask import Flask, render_template, request

# TODO: Create the Flask app instance
app = Flask(__name__)

# TODO: Define a route for "/" that accepts GET requests
#       and renders the index.html template
@app.route("/")
def index():
    return render_template("index.html")

# TODO: Define a route for "/register" that accepts POST requests
#       Inside the function:
#         - Read "name" and "sport" from request.form
#         - If either is missing or empty, render failure.html
#         - Otherwise, render success.html
@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    
    if not name or not sport:
        return render_template("failure.html")
    
    return render_template("success.html")