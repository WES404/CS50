from sys import argv
import sqlite3

def main():

    if len(argv) != 2:
        print("Not enough arguments")
        return 0

    conn = sqlite3.connect('students.db')
    db = conn.cursor()

    query = f"SELECT first, middle, last, birth FROM students WHERE house = '{argv[1]}' ORDER by last ASC, first ASC;"
    db.execute(query)

    row = db.fetchall() #pega todas as linhas

    for i in range(len(row)):
        if row[i][1] == None:
            print(row[i][0], row[i][2]+",", "born", row[i][3])
        else:
            print(row[i][0], row[i][1], row[i][2]+",", "born", row[i][3])

main()