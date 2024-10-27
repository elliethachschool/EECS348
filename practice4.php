<?php
/* 
Name: Ellie Thach
KUID: 3139476
LAB Session: 06
LAB Assignment Number: 06
Program Description: This php file makes the multiplication table with input from practice4.html.
Collaborators: None
*/
?>

<?php
$rows = $_GET['size']+1; // gets the size from html file
$columns = $_GET['size']+1; // gets the size from the html file
$teehee = " ";

echo "<table border=\"1\">";
    for ($r=0; $r < $rows; $r++) { // makes row(s) for table
        echo '<tr>';
        for ($c=0; $c < $columns; $c++) { // makes column(s) for table
            if ($r == 0 && $c == 0) {  // empties top-left cell
                echo "<td></td>";
            }
            else if ($r == 0) { // first row (header for columns)
                echo "<td>$c</td>";
            }
            else if ($c == 0) { // first column (header for rows)
                echo "<td>$r</td>";
            }
            else { // result of multiplication
                echo "<td>" .$c*$r."</td>";
            }
        }
        echo '</tr>';
    }
echo"</table>";
?>