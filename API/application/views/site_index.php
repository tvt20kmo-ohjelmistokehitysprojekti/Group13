<h1>Pankki Automaatti</h1>

<?php
defined('BASEPATH') OR exit('No direct script access allowed');
header('Access-Control-Allow-Origin: *');
header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
require APPPATH . '/libraries/REST_Controller.php';
//connection settings
$servername = "mysli.oamk.fi";
$username = "t8heos01";
$password = "sovellusprojekti";
$dbname = "opisk_t8heos01";
// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}
//$sql = "SELECT idTapahtuma, Pvm, Tapahtuma FROM Tapahtuma";
$sql = "SELECT idKortti, Haltija, idCredit, idDebit, CVV, Korttinumero, PIN FROM Kortti";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
  // output data of each row
  while($row = mysqli_fetch_assoc($result)) {
    //echo "idTapahtuma: " . $row["idTapahtuma"]. " - Pvm: " . $row["Pvm"]. " Tapahtuma: " . $row["Tapahtuma"]. "<br>";
    echo "[idKortti]: " . $row["idKortti"]. " - [Haltija]: " . $row["Haltija"]. " - [idCredit]: " . $row["idCredit"]. " - [idDebit]: " . $row["idDebit"]. " - [CVV]: " . $row["CVV"]. " - [Korttinumero]: " . $row["Korttinumero"]. " - [PIN]: " . $row["PIN"]. "<br>";
  }
} else {
  echo "0 results";
}
mysqli_close($conn);
?>