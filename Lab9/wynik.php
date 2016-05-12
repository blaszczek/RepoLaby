<!doctype html>
<html>
<head>
  <title>Kalkulator</title>
</head>
<body>
  <span style="color:red">
    WYNIK: </span>
    <?php
    $arg1=$_REQUEST['arg1'];
    $arg2=$_REQUEST['arg2'];
    $znak=$_REQUEST['op'];
    if($znak == "+") $wynik = $arg1+$arg2;
    elseif($znak == "-") $wynik = $arg1-$arg2;
    elseif($znak == "*") $wynik = $arg1*$arg2;
    elseif($znak == "/") $wynik = $arg1/$arg2;
    echo "<b>$arg1</b> $znak <b>$arg2</b> == <b>$wynik</b>";
    ?>
  <br ><a href="zad1.php">Kalkulator</a>
</body>
</html>
