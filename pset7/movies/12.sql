SELECT movies.title FROM movies INNER JOIN stars ON movies.id = stars.movie_id INNER join people ON people.id = stars.person_id
WHERE people.name = "Johnny Depp"  OR people.name = "Helena Bonham Carter"
GROUP by movies.title
having count (movies.title) > 1