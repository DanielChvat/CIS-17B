import {View} from './View.js'

export class Model{
    static CartArray = new Array();
    static page = 1;
    Search(){
        const input = document.getElementById('search-textinput');

        if(input !=null){
            $.ajax({
                type: "POST",
                url: 'search.php',
                data: {action: 'getItems', text: input.value, page: Model.page},
                success:function(n){
                    var v = new View();
                    v.displayItems(JSON.parse(n));
                }
            });
        }
    }

    static getUsers(){
        $.ajax({
            type: "POST",
            url: 'MVC/search.php',
            data: {action: 'getUsers'},
            success:function(n){
                var v = new View();
                v.displayUsers(JSON.parse(n));
            }
        });
    }

    static deleteUser(ID){
        $.ajax({
            type: "POST",
            url: 'User-AddRemove.php',
            data: {action: 'deleteUser', id: ID},
            success:function(n){
                console.log(n);
            }
        });

        location.reload();
    }

    static editUser(ID){
        const Username = prompt("New Username");
        const Password = prompt("New Password");
        const Admin = (prompt("Admin (Y/N)") === 'Y' || 'y')?1:0;


        $.ajax({
            type: "POST",
            url: 'User-AddRemove.php',
            data: {action: 'EditUser', id: ID, username: Username, password: Password, admin: Admin},
            success:function(n){
                console.log(n);
            }
        });
        location.reload();
    }

    static AddCart(name, type, price){
        const item = new Item(name, type, price);
        this.CartArray.push(item);

        console.log(this.CartArray);
        localStorage.setItem('cart', JSON.stringify(this.CartArray));
    }
}

class Item{
    constructor(name, type, price){
        this.name = name;
        this.type=type;
        this.price = price;
    }
}


export default Model;

