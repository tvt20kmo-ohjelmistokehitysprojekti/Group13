<?php
class Transaction_model extends CI_model {
  function transaction($card_id){
    $call_procedure="CALL getTransaction($card_id)";
    
    return $this->db->query($call_procedure)->result();
  }
}
