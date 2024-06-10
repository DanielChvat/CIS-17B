import {Model} from './Model.js';

const model = new Model();

export function search(){
    model.Search();
}

function init(){
    search();
    var match = document.cookie.match(RegExp('username=([^;]+)'));
    var username = decodeURIComponent(match[1]);
    const header = document.getElementById('welcome-header');
    header.appendChild(document.createTextNode("Welcome Back, " + username));
}

document.addEventListener('DOMContentLoaded', init);
