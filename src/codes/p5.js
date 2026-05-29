$(document).ready(function(){
    $("#password").on("input",function (){
        let password = $(this).val();
        let meter = $(".strength-meter")

        if(password.length<5){
            meter.text("Weak Password");
            meter.removeClass();
            meter.addClass("strength-meter weak");
        }
        else if (password.length < 8) {
      meter.text("Medium Password");
      meter.removeClass();
      meter.addClass("strength-meter medium");
    }

    // Strong
    else {
      meter.text("Strong Password");
      meter.removeClass();
      meter.addClass("strength-meter strong");
    
    }
    })
})
