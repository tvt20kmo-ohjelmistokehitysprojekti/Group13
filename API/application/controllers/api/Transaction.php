<?php

defined('BASEPATH') OR exit('No direct script access allowed');
require APPPATH . 'libraries/REST_Controller.php';

class Transaction extends REST_Controller {
    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Transaction_model');
    }

    public function transaction_post(){
        
        $card_id=$this->post('cardid');
        $result=$this->Transaction_model->transaction($card_id);

        if($result > 0){
        }
        else{
            $respond=false;
        }

        echo json_encode($result);
    }
}
