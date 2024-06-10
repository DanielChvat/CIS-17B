<?php

require 'dbconnect.php';
if (isset($_POST['action']) && $_POST['action'] == 'deleteUser'){
    $userID = $_POST['id'];
    $sql = "DELETE FROM ShoppingCartDB.entity_accounts WHERE ID = ".$userID;

    $x = $conn->query($sql);
    
    echo 'User Successfully Deleted';

}

if (isset($_POST['action']) && $_POST['action'] == 'EditUser'){
    $Username = strtolower($_POST['username']); // converting username to lowercase for case-insensitive design
    $optionsBC = ['cost' => 10];
    $Password = password_hash($_POST['password'], PASSWORD_BCRYPT, $optionsBC);
    $Admin = $_POST['admin'];


    $sql = 'UPDATE ShoppingCartDB.entity_accounts SET Username = ?, Password = ?, isAdmin = ? WHERE ID = ?';

    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ssss", $Username, $Password, $Admin, $_POST['id']);
    $stmt->execute();
    $stmt->close();
    echo 'user successfully editied';

}