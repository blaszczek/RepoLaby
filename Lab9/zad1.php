<!doctype html>
<html land="pl">
<head>
  <title>Kalkulator</title>
  <meta charset="utf-8"/>
</head>
<body>
  <form action="wynik.php">
    <table>
      <tr>
        <th style="background-color:yellow">
          Pierwszy arg:<br>
          <input type="text" name="arg1" size="8">
        </th>
        <td style="background-color:yellow">
          &nbsp;&nbsp;
        </td>
        <td style="background-color:yellow">
          <input type="radio" name="op" value="+"> <b>+</b><br>
          <input type="radio" name="op" value="-"> <b>&minus;</b><br>
          <input type="radio" name="op" value="*"> <b>&middot;</b><br>
          <input type="radio" name="op" value="/"> <b>/</b>
        </td>
        <td style="background-color:yellow">
          &nbsp;&nbsp;
        </td>
        <th style="background-color:yellow">
          Drugi arg:<br>
          <input type="text" name="arg2" size="8">
        </th>
        <td style="background-color:yellow">
          &nbsp;&nbsp;
        </td>
        <th style="background-color:yellow">
          <input type="submit" value="==">
        </th>
      </tr>
    </table>
  </form>
</body>
</html>