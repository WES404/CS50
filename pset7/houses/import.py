from cs50 import SQL
from sys import argv

db = SQL("sqlite:///students.db")


def main():
    if len(argv) != 2:
        print("Not enough arguments")
        return 0

    with open(argv[1]) as arquivo:
        for line in arquivo:
            if line.startswith("name"): continue

            line = line.strip().split(",")
            nome = line[0].split()

            if len(nome) == 2:
                nome.append(nome[1])
                nome[1] = None

            query = "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)"
            db.execute(query,nome[0], nome[1], nome[2], line[1], int(line[2]))

main()