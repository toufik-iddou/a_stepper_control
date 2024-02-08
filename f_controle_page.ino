String controlePage(){
  return "<!DOCTYPE html>\
<html lang='en'>\
<head>\
    <meta charset='UTF-8'>\
    <meta name= content='width=device-width, initial-scale=1.0'>\
    <title>PID Controller</title>\
    <style>\
    .input{\
        display: flex;\
        flex-direction: column;\
        align-items: center;\
    }\
    .container{\
        display: flex;\
        align-items: center;\
        gap: 20px;\
        flex-direction: column;\
    }\
    .inputs{\
        justify-content: space-around;\
        width: 100%;\
        display: flex;\
        gap: 20px;\
        flex-wrap: wrap;\
    }\
    .inputs-section{\
        width: max(200px,35%);\
        padding: 10px;\
        border-radius: 10px;\
        border: 1px solid gray;\
        display: flex;\
        flex-direction: column;\
        align-items: center;\
    }\
    .inputs-section > h2{\
        padding: 0 0 10px 0;\
        margin: 0;\
        width: 60%;\
        border-bottom: 1px solid gray;    \
        text-align: center;\
    }\
    input[type=submit]{\
        margin: 20px;\
        font-size: 16px;\
        padding: 5px;\
        width: 90px;\
        background-color:rgb(16, 119, 236);\
        color:white;\
        border: none;\
        border-radius: 5px;\
        cursor: pointer;\
    }\
    </style>\
</head>\
<body>\
    <form action='' method='post'>\
    <div class='container'>\
        <div class='header'>\
            <h1>PID Controller </h1>\
        </div>\
        <div class='inputs'>  \
    <div id='function-inputs' class='inputs-section'>\
        <h2>Asin(wt+φ)</h2>\
        <div class='input'>\
            <h3>Amplitude</h3>\
            <input type='range' id='a-range'  min='0' max='100' value='"+String(values.a)+"' step='0.01' onchange='updateValue(this.value,`range`,`a`);'>\
            <input type='number' step='0.01' id='a-number' name='a' value='"+String(values.a)+"'  onchange='updateValue(this.value,`number`,`a`);'>\
        </div>\
        <div class='input'>\
            <h3>Frequency</h3>\
            <input type='range' id='f-range'  min='0' max='2' value='"+String(values.f)+"' step='0.01' onchange='updateValue(this.value,`range`,`f`);'>\
            <input type='number' step='0.01' id='f-number' name='f' value='"+String(values.f)+"'  onchange='updateValue(this.value,`number`,`f`);'>\
        </div>\
        <div class='input'>\
            <h3>Phase</h3>\
            <input type='range' id='ph-range'  min='0' max='360' value='"+String(values.ph)+"'  step='0.01' onchange='updateValue(this.value,`range`,`ph`);'>\
            <input type='number' step='0.01' id='ph-number' name='ph' value='"+String(values.ph)+"'  onchange='updateValue(this.value,`number`,`ph`);'>\
        </div>\
    </div>\
    <div id='pid-inputs' class='inputs-section'>\
        <h2>PID</h2>\
    <div class='input'>\
        <h3>P</h3>\
        <input type='range' id='p-range'  min='0' max='5'  value='"+String(pidC.p)+"' step='0.01' onchange='updateValue(this.value,`range`,`p`);'>\
        <input type='number' step='0.01' id='p-number' name='p' value='"+String(pidC.p)+"'  onchange='updateValue(this.value,`number`,`p`);'>\
    </div>\
    <div class='input'> \
        <h3>I</h3>\
        <input type='range' id='i-range'  min='0' max='5'  value='"+String(pidC.i)+"' step='0.01' onchange='updateValue(this.value,`range`,`i`);'>\
        <input type='number' step='0.01' id='i-number' name='i' value='"+String(pidC.i)+"'  onchange='updateValue(this.value,`number`,`i`);'>\
    </div>\
    <div class='input'>\
        <h3>D</h3>\
        <input type='range' id='d-range'  min='0' max='5'  value='"+String(pidC.d)+"' step='0.01' onchange='updateValue(this.value,`range`,`d`);'>\
        <input type='number' step='0.01' id='d-number' name='d' value='"+String(pidC.d)+"'  onchange='updateValue(this.value,`number`,`d`);'>\
    </div>  \
    <input type='submit' value='start'>\
</div>\
    </div>\
</div>\
</form>\
</body>\
<script>\
    function updateValue(val,input,inputClass) {\
    switch(input){\
        case 'range':\
            document.getElementById(inputClass+'-number').value=val;\
        break;\
        case 'number':\
            document.getElementById(inputClass+'-range').value=val;\
        break;       \
    }\
    if(['a','f','ph'].includes(inputClass)){\
    sendUpdateRequest();\
    }\
  }\
  function sendUpdateRequest() {\
    const p =document.getElementById('p-range').value;\
    const i =document.getElementById('i-range').value;\
    const d =document.getElementById('d-range').value;\
    const a =document.getElementById('a-range').value;\
    const f =document.getElementById('f-range').value;\
    const ph =document.getElementById('ph-range').value;\
    fetch('http://192.168.4.1/params', {\
        method: 'POST',\
        headers: {\
            'Content-Type': 'application/json'\
        },\
        body: JSON.stringify({p:p,i:i,d:d,a:a,f:f,ph:ph})\
    }).then(response => {\
        if (!response.ok) {\
            throw new Error('Network response was not ok');\
        }\
        console.log('Request sent successfully');\
    }).catch(error => {\
        console.error('There was a problem with the request:', error);\
    });\
}\
</script>\
</html>";
}