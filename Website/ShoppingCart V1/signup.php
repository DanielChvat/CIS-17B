<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<div class="signup-container">
    <h1>Create an Account!</h1>
    <?php include "signup-loginmethod.php" ?>
    <form method = "POST">
        <div class="form-group">
            <label for="">Username</label>
            <input type="text" id="Username" name="Username" required> 
            <label for="">Password</label>
            <input type="text" id="Password" name="Password" required> 
        </div>
        <button type="submit" class="btn" name="signup">Sign Up</button>
    </form>
</div>
</body>
</html>