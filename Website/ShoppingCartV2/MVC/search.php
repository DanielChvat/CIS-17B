<?php

// session_start();
require '../dbconnect.php';
$display = 30;

if (isset($_POST['action']) && $_POST['action'] == 'getItems'){
    $ttuq = "SELECT COUNT(*) AS total FROM ShoppingCartDB.entity_items";
    $result = $conn->query($ttuq);
    $totalItems = $result->fetch_assoc()['total'];

    $totalPages = ceil($totalItems / $display);

    // //Determing page and offset
    $currentPage = isset($_POST['page']) ? intval($_POST['page']) :1;
    if($currentPage < 1) $currentPage = 1;
    if($currentPage > $totalPages) $currentPage = $totalPages;

    $offset = ($currentPage -1) * $display;



    // // Fetch users from the database
    if($_POST['text'] != ''){
        $sql = 'SELECT * FROM ShoppingCartDB.entity_items WHERE ItemName LIKE \'%'.$_POST['text'].'%\' LIMIT '.$display.' OFFSET '.$offset;
    }else{
        $sql = "SELECT * FROM ShoppingCartDB.entity_items LIMIT ".$display.' OFFSET '.$offset;
    }
    $items = $conn->query($sql);

    $itemsArray = array();

    if($items->num_rows != ''){
        while ($row = $items->fetch_assoc()) {
            array_push($itemsArray, $row);
        }
    }

    echo json_encode($itemsArray);
}