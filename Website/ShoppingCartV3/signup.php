<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<link rel="stylesheet" href="Styling/signup-login.css">
<body>

<div class="login-container">
    <h1>Create Account!</h1>
    <?php include 'signup-loginmethod.php' ?>
    <form method = "POST">
        <div class="form-group">
            <label>Username</label>
            <input type="text" id="Username" name="Username" required>
        </div>
        <div class="form-group">
            <label>Password</label>
            <input type="text" id="Password" name="Password" required>
        </div>
        <button type="submit" class="btn" name="signup">Sign Up</button>
    </form>
    <a href="index.php"><button id='back-button'>Back</button></a>
</div>
</body>
</html>