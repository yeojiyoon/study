function setClock(){
    var dateInfo = new Date();
    var hour = modifyNumber(dateInfo.getHours());
    var min = modifyNumber(dateInfo.getMinutes());
    var sec = modifyNumber(dateInfo.getSeconds());
    var year = dateInfo.getFullYear();
    var month = dateInfo.getMonth();
    var date = dateInfo.getDate();
    document.getElementById("time").innerHTML = hour + ":" + min + ":" + sec;
    document.getElementById("date").innerHTML = year + "년 " + month + "월 " + date + "일";
}

function setClock2(){
    var dateInfo = new Date();
    var hour = modifyNumber(dateInfo.getHours());
    var min = modifyNumber(dateInfo.getMinutes());
    var sec = modifyNumber(dateInfo.getSeconds());
    var year = dateInfo.getFullYear();
    var month = dateInfo.getMonth();
    var date = dateInfo.getDate();
    var PA;

    if(hour>=12) {
        hour = hour - 12;
        PA = "PM";
    }
    else {
        PA = "AM";
    }

    document.getElementById("time").innerHTML = PA + " " + hour + ":" + min + ":" + sec;
    document.getElementById("date").innerHTML = year + "년 " + month + "월 " + date + "일";
}

function modifyNumber(time){
    if(parseInt(time)<10){
        return "0" + time;
    }
    else
        return time;
}

window.onload = function(){
    let interval1;
    let interval2;

    setClock();
    interval1 = setInterval(setClock, 1000);


    document.getElementById("btn1").onclick = function(){
        clearInterval(interval1);
        setClock2();
        interval2 = setInterval(setClock2, 1000);
    }

    document.getElementById("btn2").onclick = function(){
        clearInterval(interval2);
        setClock();
        interval1 = setInterval(setClock, 1000);
    }
}