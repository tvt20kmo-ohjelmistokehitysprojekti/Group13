<?php
class Transaction extends REST_Controller {
  function transfer_money($first_id,$second_id,$amount){
    $call_procedure="CALL credit_transfer(?,?,?)";
    $data=array('Tilinumero'=>$first_id, 'Haltija'=>$second_id, 'Saldo'=>$amount);
    $this->db->query($call_procedure, $data);
    return $this->db->affected_rows();
  }
}
