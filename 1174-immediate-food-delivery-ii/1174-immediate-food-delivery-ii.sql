# Write your MySQL query statement below
SELECT 
    ROUND(
        100 * SUM(d.order_date = d.customer_pref_delivery_date) / COUNT(*),
        2
    ) AS immediate_percentage
FROM Delivery d
JOIN (
    SELECT customer_id, MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
) first_orders
ON d.customer_id = first_orders.customer_id
AND d.order_date = first_orders.first_order;