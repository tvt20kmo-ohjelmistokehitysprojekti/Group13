<?php

defined('BASEPATH') OR exit('No direct script access allowed');
require APPPATH . 'libraries/REST_Controller.php';

class Withdraw extends REST_Controller {
    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Withdraw_model');
    }

    public function withdraw_post(){
        
        $card_id=$this->post('cardid');
        $amount=$this->post('summa');
        $result=$this->Withdraw_model->withdraw($card_id, $amount);

        if($result > 0){
        }
        else{
            $respond=false;
        }

        echo json_encode($result);
    }
}