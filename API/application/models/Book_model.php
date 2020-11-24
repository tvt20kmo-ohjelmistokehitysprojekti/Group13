<?php
/**
 *
 */
class Book_model extends CI_model
{
  function get_book($id){
    $this->db->select('*');
    $this->db->from('Tili');
    if($id !== NULL) {
      $this->db->where('idTili',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_book($add_data){
    $this->db->insert('Tili',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_book($id, $update_data){
    $this->db->where('idTili',$id);
    $this->db->update('Tili',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_book($id){
    $this->db->where('idTili',$id);
    $this->db->delete('Tili');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}