<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script type="text/javascript">
      const module = {};
</script>
<script type="module">
    import {search} from "./Handlers.js";
    module.search = search;
</script>
<body>
    <h1>Storefront</h1>
    <input type="text" id="search-textinput" onkeyup="module.search()" placeholder="Search for Items">
    <button id="cart-button">Cart</button>
    <button id="account-button">Account</button>
    <div class="items-container">
        <ul class="item-group"></ul>
    </div>

    </script>
</body>
</html>