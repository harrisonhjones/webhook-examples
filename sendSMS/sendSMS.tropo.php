<?php
if(($number) && ($message))
{
    call($number, array("network" => "SMS"));
    say("[SparkSMS] " . $message);
}
else
{
    call("+15555555555", array("network" => "SMS"));
    say("[SparkSMS] Error, Bad Number/Message. Number: " . $number . " & Message: ". $message);
}
?>