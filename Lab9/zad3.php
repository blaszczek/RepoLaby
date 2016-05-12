<?php
header("Pragma: no-cache");
?>
<?php
$file= @fopen("Count.dat", "c+");
fscanf($file, "%d", $count);
$count++;
rewind($file);
fputs($file, $count);
fclose($file);
echo $count;
?>
