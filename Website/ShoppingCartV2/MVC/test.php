<?php
session_start();
if (isset($_POST['action']) && $_POST['action'] == 'test'){
    echo $_POST['data'];
}