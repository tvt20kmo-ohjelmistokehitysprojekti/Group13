<?php

defined('BASEPATH') OR exit('No direct script access allowed');
require APPPATH . 'libraries/REST_Controller.php';

class Transaction extends REST_Controller {
    function __construct(){
        $this->load->model('Transaction_model');
        $first_id=$this->post('Tilinumero');
        $second_id=$this->post('Haltija');
        $amount=$this->post('Saldo');
        $result=$this-Amount_model>transfer_money($first_id, $second_id, $amount);

        if($result>0){

        }
        else{
            $respond=false;
        }
        echo json_encode($result);
    }
}
  //amount_model.php?