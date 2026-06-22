CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select salary
    from (
        select salary,
            DENSE_RANK() over (order by salary DESC) as rnk
            from employee
    )t
    where rnk = N
    limit 1
  );
END