import {View} from './View.js'

export class Model{
    static CartArray = new Map();
    Search(){
        const input = document.getElementById('search-textinput');
        $.ajax({
            type: "POST",
            url: 'search.php',
            data: {action: 'getItems', text: input.value, page: 1},
            success:function(n){
                var v = new View();
                v.displayItems(JSON.parse(n));
            }
        });
    }

    static AddCart(ID){
        const count = this.CartArray.get(ID) === undefined? 0: this.CartArray.get(ID);
        this.CartArray.set(ID, count+1);
        // $.ajax({
        //     type: "POST",
        //     url: 'test.php',
        //     data: {action: 'test', data: JSON.stringify(this.CartArray)},
        //     success:function(n){
        //         console.log(n);
        //     }
        // });

        // console.log(JSON.stringify(this.CartArray, replacer));
        localStorage.setItem('cart', JSON.stringify(Array.from(this.CartArray)));
    }
}


export default Model;

