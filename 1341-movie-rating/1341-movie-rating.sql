(
    SELECT u.name AS results
    FROM Users u
    LEFT JOIN MovieRating m
    ON u.user_id = m.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(m.movie_id) DESC, u.name
    LIMIT 1
)

UNION ALL

(
    SELECT s.title AS results
    FROM Movies s
    LEFT JOIN MovieRating m
    ON s.movie_id = m.movie_id
    WHERE EXTRACT(YEAR_MONTH FROM m.created_at) = 202002
    GROUP BY s.movie_id, s.title
    ORDER BY AVG(m.rating) DESC, s.title
    LIMIT 1
);