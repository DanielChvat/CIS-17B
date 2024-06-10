<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<link rel="stylesheet" href="../Styling/storefront.css">
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script type="text/javascript">
      const module = {};
</script>
<?php
session_start();
if(!isset($_SESSION['Username'])){
    exit();
}
$username = $_SESSION['Username'];
setcookie('username', $username);
?>
<script type="module">
    import {search} from "./Controller.js";
    module.search = search;
</script>

<body>
    <h3 id='welcome-header'></h3>
    <input type="text" id="search-textinput" onkeyup="module.search()" placeholder="Search for Items">
    <a href="../cart.php"><button>Cart</button></a>
    <button id="account-button">Account</button>
    <a href="../index.php"><button>Logout</button></a>
    <div id="items-container">
        <ul id="item-group"></ul>
    </div>
</body>
</html>