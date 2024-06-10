import {Model} from './Model.js';

const itemList = document.getElementById('item-group');

export class View{
    displayItems(itemArray){
        itemList.replaceChildren();
        for(let i = 0; i < Object.keys(itemArray).length; i++){
            const div = document.createElement('div');
            div.className = 'item-card';
            const li = document.createElement('li');
            const addCartButton = document.createElement('button');
            addCartButton.appendChild(document.createTextNode('Add to Cart'));
            addCartButton.addEventListener('click', ()=>Model.AddCart(itemArray[i]['ItemID']));
            li.appendChild(document.createTextNode(itemArray[i]['ItemName']));
            li.appendChild(document.createElement('br'));
            li.appendChild(document.createTextNode('$ ' + itemArray[i]['Price']));
            li.appendChild(document.createElement('br'));
            li.appendChild(addCartButton);
            div.appendChild(li);
            itemList.appendChild(div);
        }
    }
}