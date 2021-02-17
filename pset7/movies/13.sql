SELECT people.name FROM movies INNER JOIN stars ON movies.id = stars.movie_id INNER join people ON people.id = stars.person_id
WHERE movies.title in (select movies.title from movies where people.name = "Kevin Bacon" and people.birth = 1958) AND NOT people.name = "Kevin Bacon"
