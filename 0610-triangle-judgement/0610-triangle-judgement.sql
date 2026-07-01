# Write your MySQL query statement below
Select x,y,z,
CASE 
    WHEN x+y > z
    AND y+z > x
    AND z+x > y
    Then "Yes"
    else "No"
End as triangle
FROM Triangle;