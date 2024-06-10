<?php
session_start();
require 'dbconnect.php';

if($_SESSION['Username'] != ''){
    session_destroy();
}

if($_SERVER['REQUEST_METHOD'] == 'POST') {

    if(isset($_POST['signup'])) {
        if(isset($_POST['Username']) && isset($_POST['Password'])){
            $Username = strtolower($_POST['Username']); // converting username to lowercase for case-insensitive design
            $optionsBC = ['cost' => 10];
            $Password = password_hash($_POST['Password'], PASSWORD_BCRYPT, $optionsBC);
            
            $sql = $conn->prepare('SELECT Username FROM ShoppingCartDB.entity_accounts WHERE Username = ?');
            $sql->bind_param('s', $Username);
            $sql->execute();

            $sql->store_result();

            
            
            
            if($sql->num_rows > 0) {
                echo 'Username taken';
                
            }
            
            else {
                
                $stmt = $conn->prepare('INSERT INTO ShoppingCartDB.entity_accounts (Username, Password) VALUES (?, ?)');
                $stmt->bind_param('ss', $Username, $Password);
                $stmt->execute();
                $stmt->close();
                header("Location: index.php");
            }
            
            $sql->close();
        }
    }



    if(isset($_POST['login'])) {
        if(isset($_POST['Username']) && isset($_POST['Password'])){
            $Username = strtolower($_POST['Username']);
            $Password = $_POST['Password'];

            
            
            $stmt2 = $conn->prepare('SELECT Password FROM ShoppingCartDB.entity_accounts WHERE Username = ?');
            $stmt2->bind_param('s',$Username);
            $stmt2->execute();
            $stmt2->store_result();
            $stmt2->bind_result($hashPW);
            $stmt2->fetch();
            
       
            if(password_verify($Password, $hashPW)) {
                $_SESSION['Username'] = $Username;
                echo "<script>console.log('Login successful!');</script>";
                
                $stmt = $conn->prepare("SELECT ID FROM ShoppingCartDB.entity_accounts WHERE Username = ? AND isAdmin = 1");
                $stmt->bind_param('s', $Username);
                $stmt->execute();
                $stmt->store_result();
            
                if($stmt->num_rows > 0) {
                    echo "<script>console.log('Welcome Admin!');</script>";
                    header("Location: adminMenu.php");
                }else{
                    header("Location: MVC/storefront.php");
                }

            }else{
                echo "<script>console.log('Login failed!');</script>";
          }
      }
    }
}


    