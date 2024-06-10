<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Cart</h1>

    <button>Checkout</button>

    <script type="text/javascript">
        var v = localStorage.getItem('cart');
        console.log(new Map(JSON.parse(v)));
    </script>
</body>
</html>