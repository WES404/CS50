SELECT songs.name FROM artists INNER JOIN songs ON artists.id = songs.artist_id
where artists.name = "Post Malone";