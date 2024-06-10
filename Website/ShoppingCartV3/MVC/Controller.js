import {Model} from './Model.js';
import {View} from './View.js'


//Storefront.php
const model = new Model();
const view = new View();
const leftButton = document.getElementById('left-button');
const rightButton = document.getElementById('right-button');
const pageLabel = document.getElementById('page-label');


export function search(){
    model.Search();
}

function init(){
    search();
    var match = document.cookie.match(RegExp('username=([^;]+)'));
    if(match != null){
        var username = decodeURIComponent(match[1]);
        const header = document.getElementById('welcome-header');
        header.appendChild(document.createTextNode("Welcome Back, " + username));
        pageLabel.appendChild(document.createTextNode(Model.page));
    }
}

document.addEventListener('DOMContentLoaded', init);

if(leftButton != null){
    leftButton.addEventListener('click', ()=>{
        if(Model.page > 1) Model.page--;
        pageLabel.replaceChildren();
        pageLabel.appendChild(document.createTextNode(Model.page));
        search();
    });
    rightButton.addEventListener('click', ()=>{
        Model.page++;
        pageLabel.replaceChildren();
        pageLabel.appendChild(document.createTextNode(Model.page));
        search();
    })
}

//Cart.php
const items = JSON.parse(localStorage.getItem('cart'));
const checkoutButton = document.getElementById('checkout-button');
if(checkoutButton != null){
    view.displayCart(items);
    checkoutButton.addEventListener('click', ()=>{
        localStorage.clear();
        location.href = 'index.php';
    });
}

//AdminMenu.php
const adminExitButton = document.getElementById('adminExit-button');
if(adminExitButton != null){
    Model.getUsers();
}


