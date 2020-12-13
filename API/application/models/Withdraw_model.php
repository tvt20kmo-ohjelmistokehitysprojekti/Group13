<?php
class Withdraw_model extends CI_model {
  function withdraw($card_id,$amount){
    $call_procedure="CALL withdraw($card_id,$amount)";
    $this->db->query($call_procedure);
    return $this->db->affected_rows();
  }
}
