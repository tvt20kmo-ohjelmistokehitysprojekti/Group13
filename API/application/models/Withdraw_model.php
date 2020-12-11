<?php
class Withdraw_model extends CI_model {
  function withdraw($card_id,$amount){
    $myCard = $card_id;
    $myAmount = $amount;
    $call_procedure="CALL withdraw($myCard,$myAmount)";
    $this->db->query($call_procedure);
    return $this->db->affected_rows();
  }
}
