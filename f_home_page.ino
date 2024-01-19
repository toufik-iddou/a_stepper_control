String homePage(){
 return "<!DOCTYPE html> \
        <html lang='en'> \
        <head> \
            <meta charset='UTF-8'> \
            <meta name='viewport' content='width=device-width, initial-scale=1.0'> \
            <title>Hemiche</title> \
        <style> \
                *{ \
                margin: 0; \
                box-sizing: border-box; \
            } \
            @media (min-width: 768px) { \
                .container { \
                    width: 750px; \
                } \
            } \
            @media (min-width: 992px) { \
                .container { \
                    width: 970px; \
                } \
            } \
            @media (min-width: 1200px) { \
                .container { \
                    width: 1170px; \
                } \
            } \
            .container { \
                margin: auto; \
            } \
            body{ \
                background-color: rgb(34, 34, 34); \
                color: rgb(212, 212, 212);  \
                padding:30px 0px; \
            } \
            h1 { \
                width: fit-content; \
                margin: 0 auto; \
                margin-bottom: 30px; \
            } \
            form{ \
                display: flex; \
                flex-direction: column; \
                align-items: center; \
            } \
            input[type=submit] { \
                font-family: 'Montserrat', sans-serif; \
                font-size:16px ; \
                padding: 5px ; \
                width: 80px; \
                } \
            .container { \
                margin: 0 20px 60px 20px; \
                display: grid; \
                grid-template-columns: repeat(2,minmax(350px,1fr)); \
                gap: 20px 0; \
                justify-content: space-evenly; \
                align-items: center; \
            } \
            @media (max-width:767px) { \
                .container{ \
                    grid-template-columns: repeat(1,1fr); \
                } \
            } \
            .container:first-of-type{ \
                justify-content:center \
            } \
            .container>div { \
                display: flex; \
                justify-content: center; \
                align-items: center; \
                height: fit-content; \
                 \
            } \
            .container:first-of-type>div{ \
                justify-content:center \
            } \
            .container:nth-of-type(2)>div p{ \
            width:100% \
            } \
            .container:nth-of-type(3)>div p{ \
                width:40px \
                } \
            .container:last-of-type>div:last-of-type { \
                align-self: center; \
            } \
            p { \
                font-size: 22px; \
                margin-right: 10px; \
                text-align: end; \
            } \
            select,\
            .container>div input { \
            \
                font-family: 'Montserrat', sans-serif; \
                height: 25px; \
                font-size: 16px; \
                background-color: #d8d8d8; \
                border: 0; \
                border-radius: 2px; \
            } \
               div#fix-mode-box{ \
                display: flex; \
                max-lines: 1; \
                width: 100%; \
                justify-content: center; \
                padding-bottom: 30px; \
            }    \
            .fix-point{ \
                margin : 10px;\
            } \
        </style> \
        </head> \
        <body> \
            <form action='/' method='POST'> \
            <h1>Wind properties</h1> \
            <div class='container'> \
              <div> \
                <p>velocity:</p> \
                 \
                   <input type='text' name='V' id='velocity' value='"+String(values.V)+"'> \
                 \
              </div> \
            </div> \
            <h1>Wind Turbine characteristics</h1> \
            <div class='container'> \
                <div> \
                    <p>Chord length:</p> \
                    <input type='text' name='chord' id='chord'> \
                </div> \
                <div> \
                    <p>Radius:</p> \
                     \
                   <input type='text' name='R' id='radius' value='"+String(values.R)+"'> \
                 \
                </div> \
                <div> \
                    <p>Blodes number:</p> \
                    <input type='text' name='blodes' id='blodes'> \
                </div> \
                <div> \
                    <p>Solidity:</p> \
                    <input type='text' name='solidity' id='solidity' readonly> \
                </div> \
            </div> \
            <h1>Operating Characteristics</h1> \
             \
            <div class='fix-point'> \
                 <select name ='mode'>\
                     <option "+String(values.mode==0?"selected='selected'":"")+" value=0>alpha</option>\
                     <option "+String(values.mode==1?"selected='selected'":"")+" value=1>theta</option>\
                     <option "+String(values.mode==2?"selected='selected'":"")+" value=2>movement</option>\
\
                 </select>\
\
             \
            </div> \
                 \
            <div class='container'> \
                <div> \
                    <p>TSR:</p> \
                    <input type='text' name='TSR' id='tsr' value = '"+String(values.TSR)+"'> \
                </div> \
                <div> \
                    <p>θ:</p>    \
                    <input type='text' name='theta' id='theta' value = '"+String(values.theta)+"'> \
                </div> \
                <div> \
                    <p>Ω:</p> \
                    <input type='text' name='omegaMaj' id='omegaMaj' readonly> \
                </div> \
                <div> \
                    <p>α<sub>r</sub>:</p> \
                    <input type='text' name='alpha' id='alpha' readonly> \
                </div> \
                <div> \
                <p>ω<sub>r</sub>:</p> \
                    <input type='text' name='omega' id='omega' readonly> \
                </div> \
            </div> \
            <input type='submit' value='save'> \
            </form> \
        </body> \
        <script> \
        function calculate() { \
            const velocity = Number(document.getElementById('velocity').value); \
            const tsr = Number(document.getElementById('tsr').value); \
            const radius = Number(document.getElementById('radius').value); \
            const thetad = Number(document.getElementById('theta').value); \
            const theta =Math.PI*thetad/180; \
            const alpha = 180*Math.atan(Math.sin(theta)/(Math.cos(theta)+tsr))/Math.PI; \
            const omega = tsr*velocity/radius; \
            const wr = velocity * Math.sqrt(1+(2*tsr*Math.cos(theta))+tsr**2);  \
            document.getElementById('omegaMaj').value = omega.toFixed(2); \
            document.getElementById('omega').value = wr.toFixed(2); \
            document.getElementById('alpha').value = alpha.toFixed(2); \
        } \
        const velocity = document.getElementById('velocity').addEventListener('input', function() { \
          calculate(); \
        }); \
            const tsr = document.getElementById('tsr').addEventListener('input', function() { \
          calculate(); \
        }); \
            const radius = document.getElementById('radius').addEventListener('input', function() { \
          calculate(); \
        }); \
            const theta = document.getElementById('theta').addEventListener('input', function() { \
          calculate(); \
        }); \
        calculate(); \
        </script> \
        </form> \
        </html>";
    }
