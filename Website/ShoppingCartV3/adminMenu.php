<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<link rel="stylesheet" href="Styling/storefront.css">
<?php
session_start();
if(!isset($_SESSION['Username'])){
    exit();
}
?>
<script type='module' src='MVC/Controller.js'></script>
<body>
    <h1>Admin Menu </h1>
    <a href="index.php"><button id='adminExit-button'>Exit Admin View</button></a>
    <div id="items-container">
        <ul id="item-group"></ul>
    </div>
</body>
</html>