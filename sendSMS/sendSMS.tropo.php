<?php
if(($number) && ($message))
{
    call($number, array("network" => "SMS"));
    say("[SparkSMS] " . $message);
}
else
{
    call("+14049392627", array("network" => "SMS"));
    say("[SparkSMS] Error, Bad Number/Message. Number: " . $number . " & Message: ". $message);
}
?>