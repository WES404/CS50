from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods={"GET", "POST"})

def index():

    if request.metho == "GET":
        return  render_template("index.html")

    if request.metho == "POST":
        return  render_template("greet.html")