<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cart</title>
</head>
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script type='module' src='MVC/Controller.js'></script>
<link rel="stylesheet" href="Styling/cart.css">
<body>
    <h1>Cart</h1>
    <a href="MVC/storefront.php"><button>Back To Store</button></a>
    <button id='checkout-button'>Checkout</button>
    <a href="index.php"><button>Logout</button></a>
    <div id="items-container">
        <ul id="item-group"></ul>
    </div>
</body>
</html>