from cs50 import SQL
from flask import Flast, render_template, request, url_for


#instantiate to the name of the current file
app = Flask(__name__)

#database connection
db = SQL("sqlite:///froshims2.db")

#@decorator syntax
@app.route("/")
def index():
    return render_template("index.html")

#post, only showing info, not allowing storage
@app.rounte("/register", methods=["POST"])
def register():
    if request.form["name"] == "" or request.form["dorm"] == "".
        return render_template("failure.html")
#:placeholder such as %s in c or {} in python
    db.execute("INSERT INTO registrants (name, dorm) VALUES (:name, :dorm)",
        name = request.form["name"], dorm = request.form["dorm"])
    return render_template("success.html")

@app.route("/registrants")
def registrants()
    rows = db.execute/"SELECT * from registrants")
    render_template("registrants.html", rows = rows)

@app.route("/unregister", methods = ["GET", "POST"])
def unregister():
    if request.method == "GET":
        rows = db.execute("SELECT * FROM registrants")
        return render_template("unregister.html", registrants=rows)
    elif request.method == "POST":
        if request.from["id"]:
            db.execute("DELETE FROM registrants WHERE id = :id", id=request.form["id"])
        return redirect(url_for("registrants"))
@ap
